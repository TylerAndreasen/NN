# README

@Bokay, if you end up reading this, here is a summary. I have a couple of iterations of learning systems in this repo. The primary files I am working with at the moment are as follows:

```
matrix.cpp
NN.cpp
nntest.cpp

// and the respective header files
```

As the test file implies, I am trying to get the network to learn the logic gate XOR (outputs 1 if and only if one of the two inputs is 1). I am following a tutorial series found [here](https://www.youtube.com/watch?v=XJ7HLz9VYz0&list=PLRqwX-V7Uu6aCibgK1PTWWu9by6XFdCfh) (Note: Tutorial is JavaScript, I am following it mostly to get the structure correct).

The dials I am currently tweaking are as follows:

```
NN.LEARNING_RATE := [1e-2, 1e-8]
nntest.cpp Line 49, train() iterations := [1e4, 1e6]
matrix.randomize() random generation options:
	-The current implementation
	- 1.0/rand() (Bad because most values are close to 0)
	- (float) rand() / (float) rand() (I do not recall what the issue with this was)
```

The code runs and gives outputs, but there are strange issues I would not have expected:
1. Running the training for too many iterations with some random generation options leads to positive or negative infinity being reached for the feed forward output of the four input options.
2. Other combinations of iterations tend to give the very similar answers for all four possible inputs.

I did also try subtracting the error on NN.cpp lines 143 and 144, but I think this resulted in infinite outputs again.

The most disheartening part of this project is that I at one point got an output that was basically perfect, but haven't managed to replicate the settings yet as I didn't mark them down. Unfortunately, running the problem for 1e6 iterations takes about 23 seconds on my desktop