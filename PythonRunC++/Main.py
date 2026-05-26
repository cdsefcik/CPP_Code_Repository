import subprocess

#Define the parameters
param1 = "Hello from Python"

#Execute the c++ program with parameters
result = subprocess.run([r"C:\Users\CompS\source\repos\PythonRunC++\x64\Debug\PythonRunC++.exe",param1],capture_output=True,text=True)

print(result.stdout)

input()