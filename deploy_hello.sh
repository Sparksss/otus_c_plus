#!/bin/bash
cd ./homework_01/hello_world
mkdir build
cd build/
cmake ../
cmake --build .
cmake --build . --target test
curl -T helloworld-0.0.$TRAVIS_BUILD_NUMBER-Linux.deb -usparksss:$BINTRAY_API_KEY "https://api.bintray.com/content/sparksss/otus_c_plus/helloworld/$TRAVIS_BUILD_NUMBER/helloworld-0.0.$TRAVIS_BUILD_NUMBER-Linux.deb;deb_distribution=trusty;deb_component=main;deb_architecture=amd64;publish=1"