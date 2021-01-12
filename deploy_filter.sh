#!/bin/bash
cd ./homework_01/ip_filter
mkdir build
cd build/
cmake ../
cmake --build .
cmake --build . --target test
curl -T ip_filter-0.0.$TRAVIS_BUILD_NUMBER-Linux.deb -usparksss:$BINTRAY_API_KEY "https://api.bintray.com/content/sparksss/otus_c_plus/ip_filter/$TRAVIS_BUILD_NUMBER/ip_filter-0.0.$TRAVIS_BUILD_NUMBER-Linux.deb;deb_distribution=trusty;deb_component=main;deb_architecture=amd64;publish=1"