# Format
The image can be represented by 3 matrices `red`, `green`, and `blue` which are the image's color channels.
The intermediate representation is SVD for `red`, `green`, `blue` channels which is essentialy 9 numpy arrays, stored in an .npz file using numpy.savez:

`red` = `U_red` @ `S_red` @ `V_red`
`green` = `U_green` @ `S_green` @ `V_green`
`blue` = `U_blue` @ `S_blue` @ `V_blue`

Each of the highlighted matrix can be read using $numpy$: First the file should be loaded with numpy.load and then each matrix can be accessed by the corresponding highlighted name (for example, the file was loaded into a variable $var$ then $var$[U_red] would return the $U$ matrix from SVD for red channel [SVD](https://en.wikipedia.org/wiki/Singular_value_decomposition))

$NB:$ `S_red`, `S_green`, `S_blue`, are only diagonals that should be transformed into diagonal matrices.

There is also a one-element array `k` containing the number of singular values.

# Part II of the task
Test image landscape_640x426.bmp which is compressed to a file which is 1/5 as big as the original image
Results (* k - the number of singular values):
## Standard library compression
![image](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/aee2986d-d145-4748-95b2-1a497faf4b94)
Compressed the image in 6.4 seconds

## Power method 

![image](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/e246aa3a-079e-4166-bbd1-65a6e15feaa4)
The worst method that took 7 minutes 3.6 seconds to compress the image
## Randomized SVD

![image](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/0091cb55-ec0e-4567-b2f0-92cb68ef89bd)
Compressed the image in 7.2 seconds which is slightly slower than svd from standard library

In conclusion, all three methods were equally effective in terms of size as all of them truncated matrices to 6 singular values and the image
is still recognizable: you can make out a path, some grass, tress and evening sky. However, in terms of time, power method was the worst taking roughly 60 times as many time as the other two. 

One thing to note, the implementation of randomized svd turned out to be pleasently good because it compressed the image almost as fast as standard library one.
All the algorithms for this method used are described in the book "Finding Structure with Randomness: Probabilistic Algorithms for Constructing Approximate Matrix Decompositions" by N. Halko
