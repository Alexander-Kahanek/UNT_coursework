class Fraction:
    '''
    a representation of two integers, as opposed to decimals.

    input : integers
    '''

    def __init__(self, numerator, denominator):
        '''data'''  # a/b
        try:
            numerator/denominator
        except ZeroDivisionError as err:
            print('ERROR: the denominator of a fraction cannot equal 0.')
            raise err

        if type(numerator) is not int or type(denominator) is not int:
            print('values are not integers.')
            raise TypeError

        self.n = numerator
        self.d = denominator

        self.remainder = numerator - (denominator * (numerator // denominator))
        self.whole = numerator // denominator
        self.float = numerator / denominator

    def __str__(self):
        '''printing'''
        return f'{self.n}/{self.d}'

    def reduce(self):
        '''reduce to a + remainder'''
        return f'{self} reduces to  {self.whole} + ({self.remainder}/{self.d})'

    def simplify(self):
        '''simplifies a fraction using greatest common denominator

        -- only simplifies a fraction with a denominator less than 100, due to computation time
        '''
        # how to simplify a fraction: n/d
        # check all numbers in [d, .., i, .., 1]
        # if n % i and d % i are 0
        # then i is common factor
        # else no common factors -- simplified
        for i in [self.d-k for k in range(self.d)]:
            if self.n % i == 0 and self.d % i == 0:
                if i != 1:
                    # no need for recursively simplify
                    # with greatest common factor
                    return Fraction(self.n//i, self.d//i).simplify()
                else:
                    # gcd is 1 and cannot be simplified
                    return Fraction(self.n, self.d)

        return Fraction((self.whole*self.d) + self.remainder, self.d)

    def invert(self):
        '''flips fraction from a/b to b/a'''
        return Fraction(self.d, self.n)

    def __add__(self, other):  # a/b, c/d
        '''addition + '''
        # a*d + c*b / b*d
        return Fraction((self.n*other.d) + (other.n*self.d), self.d*other.d)

    def __sub__(self, other):  # a/b, c/d
        '''subtraction - '''
        # a*d - c*b / b*d
        return Fraction((self.n*other.d) - (other.n*self.d), self.d*other.d)

    def __mul__(self, other):  # a/b, c/d
        '''multiplication * '''
        # a*c / b*d
        return Fraction(self.n*other.n, self.d*other.d)

    def __truediv__(self, other):  # a/b, c/d
        '''division / '''
        # a*d / b*c
        return Fraction(self.n*other.d, self.d*other.n)

    def __mod__(self, other):  # a/b, c/d
        '''modulo % '''
        # a/b - c/d * (a/b // c/d)
        return self - other * (self // other)

    def __floordiv__(self, other):  # a/b, c/d
        '''floor division // '''
        return Fraction((self/other).whole, 1)

    def __pow__(self, other):  # a/b, c/d
        '''exponentiation ** 

        -- only works for fractions with 1 in the denominator as the power
        '''
        a, b = ((self.n**other.n)**(1/other.d)).as_integer_ratio()
        c, d = ((self.d**other.n)**(1/other.d)).as_integer_ratio()
        # print(a, b, c, d)
        return Fraction(a*d, c*b).simplify()
