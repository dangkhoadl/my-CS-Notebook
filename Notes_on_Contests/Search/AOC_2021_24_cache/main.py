#!/usr/bin/env python3
import sys, os
from functools import lru_cache

sys.stdin = open('input.in', 'r')
sys.setrecursionlimit(int(1e7))


@lru_cache(maxsize=None)
def guess(idx, w_val, x_val, y_val, z_val):
    def get_second(var):
        return values[var] if var in values.keys() else int(var)

    values = {
        'w': w_val,
        'x': x_val,
        'y': y_val,
        'z': z_val
    }
    # Prune
    if values['z'] > int(1e6): return (False, '')

    # Debug
    print(f"[Cache info: {guess.cache_info()}][{idx}/{len(ops)}]:", w_val, x_val, y_val, z_val)

    # End
    if idx == len(ops):
        return (True, '') if values['z'] == 0 else (False, '')

    # ALU
    op = ops[idx]

    if op[0] == 'inp':
        for digit in [1,2,3,4,5,6,7,8,9]:
            values[op[1]] = digit
            res = guess(idx + 1, values['w'], values['x'], values['y'], values['z'])

            if res[0] == True: return (True, str(digit) + res[1])
        return (False, '')

    second_op = get_second(op[2])
    if op[0] == 'add':
        values[op[1]] += second_op
    elif op[0] == 'mul':
        values[op[1]] *= second_op
    elif op[0] == 'div':
        if second_op == 0: return (False, '')
        values[op[1]] //= second_op
    elif op[0] == 'mod':
        if values[op[1]] < 0 or second_op <= 0: return (False, '')
        values[op[1]] %= second_op
    elif op[0] == 'eql':
        if values[op[1]] == second_op:
            values[op[1]] = 1
        else:
            values[op[1]] = 0
    else:
        return (False, '')
    return guess(idx + 1, values['w'], values['x'], values['y'], values['z'])


if __name__ == "__main__":
    # Read inputs
    global ops
    lines = [line.strip() for line in sys.stdin.readlines()]
    ops = [line.split() for line in lines]

    # Search
    ans = guess(0, 0,0,0,0)
    print(f'Correct: {ans[1]}')
