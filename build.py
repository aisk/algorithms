#! /usr/bin/env python2.7
# coding: utf-8

import os
import sys


def build(source):
    target = source[:-3]
    sys.stdout.write('compile [%(source)s] ... ' % locals())
    result = os.system('clang++ %(source)s -o %(target)s' % locals())
    if result == 0:
        sys.stdout.write('done!\n')
    else:
        sys.stdout.write('failed!\n')


def all():
    files = os.listdir('.')
    sources = [x for x in files if x.endswith('.cc')]
    map(build, sources)


if __name__ == '__main__':
    all()
