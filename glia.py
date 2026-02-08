import os

executable_name = "nnexec.exe"
cpp_files = "nntest.cpp NN.cpp matrix.cpp"

init_iterations = 100
init_learning_rate = 1e-3

# running other file using run()
os.system(f"g++ {cpp_files} -o {executable_name}")

os.system(f"start {executable_name} {init_iterations} _ {init_learning_rate}")