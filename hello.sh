# CPUPROFILE="eigenprof.log" R -f "hello.R"
R -f hello.R > /dev/null && google-pprof --text $(which R) eigen-prof.log 
