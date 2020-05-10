.PHONY: clean All

All:
	@echo "----------Building project:[ Paranthesization - Debug ]----------"
	@cd "Paranthesization" && "$(MAKE)" -f  "Paranthesization.mk"
clean:
	@echo "----------Cleaning project:[ Paranthesization - Debug ]----------"
	@cd "Paranthesization" && "$(MAKE)" -f  "Paranthesization.mk" clean
