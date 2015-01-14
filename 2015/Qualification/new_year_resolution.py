import collections
import functools

class memoized(object):
   '''Decorator. Caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned
   (not reevaluated).
   '''
   def __init__(self, func):
      self.func = func
      self.cache = {}
   def __call__(self, *args):
      if not isinstance(args, collections.Hashable):
         # uncacheable. a list, for instance.
         # better to not cache than blow up.
         return self.func(*args)
      if args in self.cache:
         return self.cache[args]
      else:
         value = self.func(*args)
         self.cache[args] = value
         return value
   def __repr__(self):
      '''Return the function's docstring.'''
      return self.func.__doc__
   def __get__(self, obj, objtype):
      '''Support instance methods.'''
      return functools.partial(self.__call__, obj)
   def reset(self):
      self.cache = {}
# tuple is hashable, list not
@memoized
def solve(n, tar, foods):
    #m = max([tp, tc, tf])
    #print ', '.join(map(str, [n, tar]))
    if max(tar) == 0:
      return True
    if n == 0 and any(map(lambda a:a > 0, tar)):
        return False
    #food_pcf = map(int, raw_input.strip().split())
    #p, c, f = map(int, raw_input().strip().split())
    if any(x > y for x, y in zip(foods[n-1], tar)):
        #print [x - y for x, y in zip(foods[n-1], tar)]
        return solve(n - 1, tar, foods)
    return solve(n - 1, tuple(x - y for x, y in zip(tar, foods[n-1])), foods) or solve(n - 1, tar, foods)
    

if __name__ == '__main__':
    t = int(raw_input().strip())
    #tar = map(int, raw_input().split())
    for i in xrange(1, t+1):
        tar = tuple(map(int, raw_input().strip().split()))
        n = int(raw_input().strip())
        foods = []
        for j in xrange(n):
            #print j
            foods.append(tuple(map(int, raw_input().strip().split())))
        foods = tuple(foods)
        rst = solve(n, tar, foods)
        #print len(solve.cache)
        solve.reset()
        #print len(solve.cache)
        print 'Case #%d: %s' % (i, 'yes' if rst else 'no')