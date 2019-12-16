GEN = $(filter-out harness.c, $(wildcard *.c))
RES = $(GEN:%.c=%.res)
EXE = $(GEN:%.c=%)
REPS = 1000000000
NUM_REPS = 10

default: $(RES)

%.res:
	./compile.sh $(@:%.res=%) $(REPS) $(NUM_REPS) > $@

clean:
	@rm $(wildcard *.res) $(EXE)
