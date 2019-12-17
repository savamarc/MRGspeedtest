GEN = $(filter-out harness.c, $(wildcard *.c))
RES = $(GEN:%.c=%.res)
EXE = $(GEN:%.c=%)
REPS = 1000000000
NUM_REPS = 10

default: $(RES) clean results

%.res:
	./compile.sh $(@:%.res=%) $(REPS) $(NUM_REPS) > $@

results:
	@cat results.txt

clean:
	./average.py
	@rm $(RES) $(EXE)
