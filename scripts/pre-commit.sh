#!/bin/sh
# Установка: ln -s ../../scripts/pre-commit.sh .git/hooks/pre-commit
set -eu
cd "$(git rev-parse --show-toplevel)"
exec python3 scripts/build.py --hook
