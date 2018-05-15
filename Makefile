
src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
dep = $(obj:.o=.d)

CXX = g++
CXXFLAGS = -Wall -g -std=c++11
GMPFLAGS = -lgmpxx -lgmp
LDFLAGS =

print-%: 	# make print-CXXFLAGS    for example
	@echo '$(subst ','\'',$*=$($*)) (origin: $(origin $*), flavor: $(flavor $*))'	

all: 
	@echo please specify a target:
	@echo "  primes"
	@echo "  poly_perform"
	@echo "  test_rat  --  test the Rational class"
	@echo "  bernoulli"
	@echo
	@echo "  clean"
	@echo "  cleandep"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ -c $<

primes: primes.o 
	$(CXX) $(CXXFLAGS) -o $@ $< $(GMPFLAGS) 

poly_perform: poly_perform.o fft.o
	$(CXX) $(CXXFLAGS) -o $@ $^

test_rat: test_rat.o 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GMPFLAGS) 

bernoulli: bernoulli.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GMPFLAGS) 

-include $(dep)

%.d: %.cpp
	@$(CXX) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean 
clean: cleandep 
	rm -f $(obj) primes poly_perform test_rat bernoulli 

.PHONY: cleandep
cleandep:
	rm -f $(dep)

