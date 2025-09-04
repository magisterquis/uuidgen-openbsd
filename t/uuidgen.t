#!/usr/bin/env perl
#
# uuidgen.t
# Test uuidgen
# By J. Stuart McMurray
# Created 20250804
# Last Modified 20250804

use autodie;
use warnings;
use strict;

use Test::More;

my $NITER = 10;

plan tests => (2 * $NITER) + 1;

# Can we generate UUIDs?
my @uuids;
for my $i (1..$NITER) {
        my $uuid = `./uuidgen`;
        is $?, 0, "UUID $i/$NITER generated ok";
        like $uuid, qr/^[0-9a-f]{8}(-[0-9a-f]{4}){3}-[0-9a-f]{12}$/, 
                "UUID $i/$NITER formatted correctly";
        push @uuids, $uuid;
}

# Were they all different?
my %got;
for my $uuid (@uuids) {
        diag "Duplicate UUID: $uuid" unless (1 == ++$got{$uuid});
}
is 0+(keys %got), $NITER, "Generated $NITER unique UUIDs";
