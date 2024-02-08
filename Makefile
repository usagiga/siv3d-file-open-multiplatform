.PHONY: xxx
xxx:
	@echo "Please select optimal option."

.PHONY: fmt
fmt:
	@find . -regextype posix-extended -regex ".*\.(c|cpp|h|hpp)" | xargs -IX clang-format -i --verbose X

