alias clr='printf "\ec"'
alias gdb='gdb -q'
alias py='python3'
co() { g++ "$1".cpp -o "$1" -std=c++14 -ggdb3 -fsanitize=address,undefined -D_GLIBCXX_DEBUG -Wall -Wextra -Wshadow -Wconversion; }
run() { co "$1" && ./"$1"; }
co2() { g++ "$1".cpp -o "$1" -std=c++14 -O2; }
run2() { co2 "$1" && /usr/bin/time -v ./"$1"; }
