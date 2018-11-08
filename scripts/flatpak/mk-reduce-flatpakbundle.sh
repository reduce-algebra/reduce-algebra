#! /bin/sh

flatpak-builder --repo reduce.repo --force-clean build de.camusings.Reduce.json

flatpak build-bundle reduce.repo reduce.flatpak de.camusings.Reduce

/usr/bin/rm -rf build reduce.repo .flatpak
