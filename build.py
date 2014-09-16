#! /usr/bin/env python2.7
# coding: utf-8

import os
import sys


files = os.listdir('.')
sources = [x for x in files if x.endswith('.cc')]


def build(source):
    target = source[:-3]
    sys.stdout.write('compile [%(source)s] ... ' % locals())
    result = os.system('clang++ -std=c++11 -g %(source)s -o %(target)s' % locals())
    if result == 0:
        sys.stdout.write('done!\n')
    else:
        sys.stdout.write('failed!\n')


def build_all():
    map(build, sources)


def clean(source):
    target = source[:-3]
    sys.stdout.write('clean [%(source)s] ... ' % locals())
    result = os.system('rm -rf %(target)s %(target)s.dSYM' % locals())
    if result == 0:
        sys.stdout.write('done!\n')
    else:
        sys.stdout.write('failed!\n')


def clean_all():
    map(clean, sources)


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print 'useage: build.py [build|clean|run]'
        sys.exit(1)
    if sys.argv[1] == 'build':
        build_all()
    elif sys.argv[1] == 'clean':
        clean_all()
    else:
        sys.exit(1)
