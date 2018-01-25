# W I P


# getdns

Query Domain Name System Using the ‘getdns’ Application Programming
Interface

## Description

[`getdns`](https://getdnsapi.net/) is a modern asynchronous DNS API. It
implements DNS entry points from a design developed and vetted by
application developers, in an API specification. The open source C
implementation of getdns is developed and maintained in collaboration by
NLnet Labs, Sinodun and No Mountain Software.

## Stuff you need

Until an auto/anticonf is in place:

  - `libgetdns-dev` / `libgetdns6` (debian/ubuntu)
  - `brew install getdns` (macOS)

(they need to be available on the proper paths for the compilers to find
them)

the rest of you are on your own for a bit

## What’s Inside The Tin

Nothing yet except proof it that the C interface works as advertised.

The following functions are implemented:

## Installation

``` r
devtools::install_github("hrbrmstr/getdns")
```

## Usage

``` r
library(getdns)

# current verison
packageVersion("getdns")
```

    ## [1] '0.1.0'
