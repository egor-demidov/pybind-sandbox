from pybind_sandbox import add, process_array, ExampleClass
import numpy as np

print(add(1, 2))

process_array(np.array([1, 2, 3]))

instance = ExampleClass(1, 2)
print(instance.get_secret())
