# MergeSort (Without Heap Allocations) vs (Classic)
tested in release mode (x64) - Ryzen 5 5600X

# Banchmark Test
 - (Benchmark Test Number)
 - (how many random numbers)
 - (Time to sort in Millisecond/Second)
 - (Total allocted in MB/GB) 
 
  # Classic MergeSort Benchmark:
-----------------------------------------------------------------------------------------------------------------------------------------------------
    (1)      100000:        : sorted in     12.292 ms,      0.012 s,        6 MB,        0 GB (Total Allocated!, Not at the same Time)
    (2)     1000000:        : sorted in    113.267 ms,      0.113 s,       79 MB,        0 GB (Total Allocated!, Not at the same Time)
    (3)    10000000:        : sorted in   1170.102 ms,      1.170 s,      932 MB,        0 GB (Total Allocated!, Not at the same Time)
    (4)   100000000:        : sorted in  12374.971 ms,     12.375 s,    10663 MB,       10 GB (Total Allocated!, Not at the same Time)
    (5)  1000000000:        : sorted in 132001.156 ms,    132.001 s,   119705 MB,      119 GB (Total Allocated!, at the same Time(about 11,2 GB))
-----------------------------------------------------------------------------------------------------------------------------------------------------

 # (In Place) MergeSort Benchmark:
-----------------------------------------------------------------------------------------------------------------------------------------------------
    (1)      100000:        : sorted in      1.859 ms,      0.002 s,     0 MB,     0 GB (Total Allocated!)
    (2)     1000000:        : sorted in     22.249 ms,      0.022 s,     0 MB,     0 GB (Total Allocated!)
    (3)    10000000:        : sorted in    262.601 ms,      0.263 s,     0 MB,     0 GB (Total Allocated!)
    (4)   100000000:        : sorted in   2900.102 ms,      2.900 s,     0 MB,     0 GB (Total Allocated!)
    (5)  1000000000:        : sorted in  32533.127 ms,     32.533 s,     0 MB,     0 GB (Total Allocated!)

-----------------------------------------------------------------------------------------------------------------------------------------------------
