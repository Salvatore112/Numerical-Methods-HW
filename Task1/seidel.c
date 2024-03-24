#include "seidel.h"

net* initialize_net(int N, int block_size, function f, function u) {

    net* initialized_net = malloc(sizeof(*initialized_net));
    initialized_net->N = N;
    initialized_net->h = 1.0 / (N - 1);
    initialized_net->u = make_array(N,N);
    initialized_net->f = make_array(N,N);
    initialized_net->block_size = block_size;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0)
            {
                initialized_net->u[i][j] = u(0, j * initialized_net->h);
            }
            else if (j == 0)
            {
                initialized_net->u[i][j] = u(i * initialized_net->h, 0);
            }
            else if (i == (N - 1))
            {
                initialized_net->u[i][j] = u(1, j * initialized_net->h);
            }
            else if (j == (N - 1))
            {
                initialized_net->u[i][j] = u(i * initialized_net->h, 1);
            }
            else
            {
                initialized_net->u[i][j] = 0;
            }
            initialized_net->f[i][j] = f(i * initialized_net->h, j * initialized_net->h);
        }
    }
    return initialized_net;
}

static double processBlock(net* nt, int a, int b) {

    int iStart = 1 + a * nt->block_size;
    int jStart = 1 + b * nt->block_size;

    int iFin = min(iStart + nt->block_size, nt->N - 1);
    int jFin = min(jStart + nt->block_size, nt->N - 1);

    double dm = 0;
    for (int i = iStart; i < iFin; i++) {
        for (int j = jStart; j < jFin; j++) {
            double temp = nt->u[i][j];
            nt->u[i][j] = 0.25 * (nt->u[i - 1][j] + nt->u[i + 1][j] + nt->u[i][j - 1] + nt->u[i][j + 1] -
                                  nt->h * nt->h * nt->f[i][j]);
            double d = fabs(temp - nt->u[i][j]);
            if (dm < d) {
                dm = d;
            }
        }
    }
    return dm;
}

int seidel(net* nt, double eps) {
    int counter = 0;
    int blocks = (nt->N - 2) / (nt->block_size);
    if (nt->block_size * blocks != (nt->N - 2))
        blocks += 1;
    double dmax = 0;
    double* dm = calloc(blocks, sizeof(*dm));

    do {
        counter++;
        dmax = 0;
        for (int nx = 0; nx < blocks; nx++) {
            dm[nx] = 0;

            int i, j = 0;
            double d = 0;

#pragma omp parallel for shared(nt, nx, dm) private(i, j, d)
            for (i = 0; i < nx + 1; i++) {
                j = nx - i;
                d = processBlock(nt, i, j);
                if (dm[i] < d) {
                    dm[i] = d;
                }
            } // the end of parallel region
        } // wave attenuation

        for (int nx = blocks - 2; nx >= 0; nx--) {

            int i, j = 0;
            double d = 0;

#pragma omp parallel for shared(nt, nx, dm) private(i, j, d)
            for (i = blocks - nx - 1; i < blocks; i++) {
                j = blocks + ((blocks - 2) - nx) - i;
                d = processBlock(nt, i, j);
                if (dm[i] < d) {
                    dm[i] = d;
                }
            } // the end of parallel region
        }

        for (int i = 0; i < blocks; i++) {
            if (dmax < dm[i]) {
                dmax = dm[i];
            }
        }
    } while (dmax > eps);
    free(dm);

    return counter;
}

void delete_net(net* net) {
    delete_array(net->u, net->N);
    delete_array(net->f, net->N);
    free(net);
}