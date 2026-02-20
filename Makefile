cc = gcc 
src = server.c 
out = server 

all: compile run # no cleaning for now

compile:
	@echo "[info] compiling "
	@$(cc) $(src) -o $(out)

run:
	@chmod +x $(out)
	@./$(out)

.PHONY: compile run
