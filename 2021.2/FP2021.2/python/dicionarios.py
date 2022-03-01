sample = {'key1':'value1', '2':'2', 3:'ok 3'}
sample2 = {'key1':'value1', '2':'2', 3:'jesus is lord'}

print(list(sample))
print(sample.items())


for i in sample:
    print(sample[i])
    print(sample.get(i))

sample.pop(3)
print(sample)

sample.update({'luis':'ok'})
print(sample)