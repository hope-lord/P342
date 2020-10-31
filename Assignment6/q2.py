from integrate import*
f2=lambda x: x/(1+x)


print(" "*5+"|"+"%15s"%"Midpoint"+" |"+"%15s"%"Trapezoidal"+" |"+"%15s"%"Simposon"+" |")
for i in [6,10,26]:
    print("%5s | "%f"N=%02d"%i,end='')
    print("%0.12f | "%(midpoint(f2,1,3,None,None,None,i)),end='')
    print("%0.12f | " % (trapezoidal(f2, 1, 3, None, None, None, i)),end='')
    print("%0.12f |"%(simpson(f2, 1, 3,None, None, None, i)))

#Output
'''
     |       Midpoint |    Trapezoidal |       Simposon |
N=06 | 1.307715679125 | 1.305122655123 | 1.306830206830 |
N=10 | 1.307164639590 | 1.306228596825 | 1.306849769311 |
N=26 | 1.306899032304 | 1.306760380902 | 1.306852751307 |

'''
