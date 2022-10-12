# 6_tuple_representation
This program serves the purpose of constructing the plat slide moves for a chosen Heegaard diagram of a 3-manifold, represented through a 6-tuple of integers. 
For further informations about the algorithm and theoretical background, please refer to [An algorithmic method to compute plat-like Markov moves in genus two 3-manifolds](https://arxiv.org/abs/2112.13718)

## Make instructions

The Makefile is built for Linux operating sistems. 
It is sufficient to call the command make: 

```bash
make
```

## Usage
```bash
# returns the correct plat slide moves if the problem is well-posed
./6_tuple
Input the 6-tuple like so: h_0 h_1 h_2 q_0 q_1 q_2 (values less than 50)
2 2 2 1 1 1

The 0-word is: a_r^{-1} b_r a_l^{-1} a_r^{-1}

The 1-word is: a_l b_l b_r^{-1} a_r^{-1} b_r

The 2-word is: a_l^{-1} b_l^{-1} a_l^{-1} a_r^{-1} b_r

# returns an error message if not
./6_tuple
Input the 6-tuple like so: h_0 h_1 h_2 q_0 q_1 q_2 (values less than 50)
1 2 3 1 2 3
The 6-tuple doesn't correspond to a manifold, closing with error. 
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
