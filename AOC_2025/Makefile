
CXX = clang++

CXXFLAGS = -std=c++23 -Wall -Wextra -DCLI 

% : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<



.PHONY: clean

clean:
	@echo "Removing all Mach-O executables in the current directory..."
	@find . -type f -perm +111 -exec sh -c 'file -bI "$$0" | grep -q "application/x-mach-binary"' {} \; -print -delete 
	@echo "Clean complete."
