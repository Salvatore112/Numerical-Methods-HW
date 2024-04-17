# Format
The intermediate representation is SVD for red, green, blue channels which is essentialy 9 numpy arrays and 1 element array containing the number of singular values: 

- U_red - the first array from SVD
- S_red - the diagonal of the second array from SVD
- V_red - the third array from SVD
- U_green - the first array from SVD
- S_green - the diagonal of the second array from SVD
- V_green - the third array from SVD
- U_blue - the first array from SVD
- S_blue - the diagonal of the second array from SVD
- V_blue - the third array from SVD
- k - one element array containing the number of singular values

All these arrays are stored in a ".npz" file that numpy provides for storing numpy arrays