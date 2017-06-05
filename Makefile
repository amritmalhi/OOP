.PHONY: clean All

All:
	@echo "----------Building project:[ Week-1 - Debug ]----------"
	@cd "template-week-1" && "$(MAKE)" -f  "Week-1.mk"
clean:
	@echo "----------Cleaning project:[ Week-1 - Debug ]----------"
	@cd "template-week-1" && "$(MAKE)" -f  "Week-1.mk" clean
