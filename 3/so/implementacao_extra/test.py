my_output = '''Total Memory 50
Allocate 5 to P0 with Best Fit
Allocate 10 to P1 with Best Fit
Allocate 15 to P2 with Best Fit
Addresses [0:4] P0
Addresses [5:14] P1
Addresses [15:29] P2
Addresses [30:49] Unused
Release P1
Addresses [0:4] P0
Addresses [5:14] Unused
Addresses [15:29] P2
Addresses [30:49] Unused
Allocate 5 to P0 with Worst Fit
Addresses [0:4] P0
Addresses [5:14] Unused
Addresses [15:29] P2
Addresses [30:34] P0
Addresses [35:49] Unused
Compact Memory
Addresses [0:4] P0
Addresses [5:19] P2
Addresses [20:24] P0
Addresses [25:49] Unused
Fail to release P1
The request of P0 fail
Exit'''

erico_output = '''Total Memory 50
Allocate 5 to P0 with Best Fit
Allocate 10 to P1 with Best Fit
Allocate 15 to P2 with Best Fit
Addresses [0:4] P0
Addresses [5:14] P1
Addresses [15:29] P2
Addresses [30:49] Unused
Release P1
Addresses [0:4] P0
Addresses [5:14] Unused
Addresses [15:29] P2
Addresses [30:49] Unused
Allocate 5 to P0 with Worst Fit
Addresses [0:4] P0
Addresses [5:14] Unused
Addresses [15:29] P2
Addresses [30:34] P0
Addresses [35:49] Unused
Compact Memory
Addresses [0:4] P0
Addresses [5:19] P2
Addresses [20:24] P0
Addresses [25:49] Unused
Fail to release P1
The request of P0 fail
Exit'''

print(my_output == erico_output)
