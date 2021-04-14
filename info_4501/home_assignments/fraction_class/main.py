from fractions import *

print()
#######################

print('--- setup -----------------')

try:
    print(f'attempting fraction 17/0 ...')
    Fraction(17, 0)
except:
    print()
    pass

f1, f2 = Fraction(1, 2), Fraction(6, 1)
print(f'fraction 1 : f1 = {f1}')
print(f'fraction 2 : f2 = {f2}')
######################

print('--- math -------------------')

# addition
print(f'{f1} + {f2} = {f1 + f2}')
# subtraction
print(f'{f1} - {f2} =  {f1 - f2}')
# multiplication
print(f'{f1} * {f2} =  {f1 * f2}')
# division
print(f'{f1} / {f2} =  {f1 / f2}')
# floor division
print(f'{f2} // {f1} = {f2 // f1}')
# modulo
print(f'{Fraction(7,1)} % {Fraction(2,1)} = {Fraction(7,1) % Fraction(2,1)}')
# exponentiation
# only works with a whole number as fraction 2
print(f'{f1} ** {f2} = {f1 ** f2}')
# print(f'{Fraction(2,1)} ** {Fraction(5,4)} = {Fraction(2,1) ** Fraction(5,4)}')
# print(2**(5/4), (Fraction(2, 1) ** Fraction(5, 4)).float)
#####################

print('--- simplifying ------------')

print(f'{f1} = {f1.simplify()}')
print(f'{f2} = {f2.simplify()}')
print(f'18/602 = {Fraction(18,602).simplify()}')
print(f'72/144 = {Fraction(72,144).simplify()}')
print(f'0/13 = {Fraction(0,10).simplify()}')
####################

print('--- other things -----------')

print(f'convert to float ... {f1} = {f1.float}, {f2} = {f2.float}')
print(f'inverting a fraction ... {f1} inverts to {f1.invert()}')
####################

print()
