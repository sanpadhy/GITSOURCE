functions = []
for i in range(10):
    functions.append(lambda : i)

print(functions)

i = 0
for f in functions:
    print(f())
    i += 1
