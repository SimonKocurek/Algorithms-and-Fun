def cons(a, b):
    return lambda f : f(a, b)

def car(f):
    def extractor(a, b):
        return a

    return f(extractor)

def cdr(f):
    def extractor(a, b):
        return b

    return f(extractor)

print(car(cons(1, 3)))
print(cdr(cons(1, 3)))

