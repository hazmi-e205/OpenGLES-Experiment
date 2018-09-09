#!/bin/sh

git clean -fdx
# Git Cleanup more simple
# -f: force git clean to delete the files
# -d: delete untracked directories in addition to untracked files
# -x: delete files that are ignored by git
