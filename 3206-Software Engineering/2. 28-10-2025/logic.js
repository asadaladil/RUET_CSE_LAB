/**
 * The Calculator class handles all the logic and state.
 */
class Calculator {
    constructor(previousOperandTextElement, currentOperandTextElement) {
        this.previousOperandTextElement = previousOperandTextElement;
        this.currentOperandTextElement = currentOperandTextElement;
        this.clear(); // Set default values on startup
    }

    // Resets the calculator to its default state
    clear() {
        this.currentOperand = '0';
        this.expression = []; // This will store our full expression, e.g., ['5', '+', '10']
        this.readyToReset = false; // Used to clear display after '='
        this.updateDisplay();
    }

    // Appends a number or decimal point to the current number
    appendNumber(number) {
        // Prevent multiple decimal points
        if (number === '.' && this.currentOperand.includes('.')) return;
        
        // If we just hit equals, start a new number
        if (this.readyToReset) {
            this.currentOperand = number;
            this.readyToReset = false;
        } else {
            // Handle starting with 0
            if (this.currentOperand === '0' && number !== '.') {
                this.currentOperand = number;
            } else {
                this.currentOperand = this.currentOperand.toString() + number.toString();
            }
        }
        this.updateDisplay();
    }

    // Handles the "AC", "+/-", and "%" buttons
    handleFunction(func) {
        switch (func) {
            case 'ac':
                this.clear();
                break;
            case 'toggle':
                if (this.currentOperand === '0') return;
                this.currentOperand = this.currentOperand * -1;
                this.updateDisplay();
                break;
            case 'percent':
                this.currentOperand = this.currentOperand / 100;
                this.updateDisplay();
                break;
        }
    }

    // Sets the chosen operation (+, -, etc.)
    chooseOperation(operation) {
        // Don't add an operation if the user hasn't typed a number
        if (this.currentOperand === '' && this.expression.length > 0) {
            // This lets the user change their mind (e.g., from '+' to '-')
            this.expression[this.expression.length - 1] = operation;
            this.updateDisplay();
            return;
        }

        if (this.currentOperand === '') return;

        // Add the number and operation to our expression
        this.expression.push(this.currentOperand);
        this.expression.push(operation);
        
        this.currentOperand = '0'; // Reset for the next number
        this.readyToReset = false;
        this.updateDisplay();
    }

    // Performs the BODMAS calculation
    compute() {
        // Don't compute if there's nothing to compute
        if (this.expression.length === 0) return;
        
        // Add the final number (the currentOperand) to the expression
        this.expression.push(this.currentOperand);

        // Create a copy of the expression to work with
        let calc = [...this.expression];

        // --- BODMAS Pass 1: Multiplication and Division ---
        let i = 0;
        while (i < calc.length) {
            const op = calc[i];
            if (op === '×' || op === '÷') {
                const left = parseFloat(calc[i - 1]);
                const right = parseFloat(calc[i + 1]);
                let result;

                if (op === '×') {
                    result = left * right;
                } else {
                    if (right === 0) {
                        alert("Cannot divide by zero!");
                        this.clear();
                        return;
                    }
                    result = left / right;
                }
                
                // Replace [left, op, right] with [result]
                calc.splice(i - 1, 3, result.toString());
                i = 0; // Restart the loop
            } else {
                i++;
            }
        }

        // --- BODMAS Pass 2: Addition and Subtraction ---
        i = 0;
        while (i < calc.length) {
            const op = calc[i];
            if (op === '+' || op === '-') {
                const left = parseFloat(calc[i - 1]);
                const right = parseFloat(calc[i + 1]);
                let result;

                if (op === '+') {
                    result = left + right;
                } else {
                    result = left - right;
                }
                
                // Replace [left, op, right] with [result]
                calc.splice(i - 1, 3, result.toString());
                i = 0; // Restart the loop
            } else {
                i++;
            }
        }
        
        // The only item left in 'calc' is the final answer
        this.currentOperand = calc[0];
        this.expression = []; // Clear the expression
        this.readyToReset = true; // Set flag to clear display on next number
        this.updateDisplay();
    }

    // Formats numbers with commas and handles operators
    getDisplayNumber(item) {
        const stringItem = item.toString();
        
        // Check if it's an operator
        if (['+', '-', '×', '÷'].includes(stringItem)) {
            return ` ${stringItem} `; // Add spaces for readability
        }

        // It's a number, format it
        const integerDigits = parseFloat(stringItem.split('.')[0]);
        const decimalDigits = stringItem.split('.')[1];
        
        let integerDisplay;
        if (isNaN(integerDigits)) {
            integerDisplay = '';
        } else {
            integerDisplay = integerDigits.toLocaleString('en', { maximumFractionDigits: 0 });
        }
        
        if (decimalDigits != null) {
            return `${integerDisplay}.${decimalDigits}`;
        } else {
            return integerDisplay;
        }
    }

    // Updates the text on the display screen
    updateDisplay() {
        this.currentOperandTextElement.innerText = 
            this.getDisplayNumber(this.currentOperand);
        
        // Display the entire expression in the previous operand area
        if (this.expression.length > 0) {
            this.previousOperandTextElement.innerText = 
                this.expression.map(item => this.getDisplayNumber(item)).join('');
        } else {
            this.previousOperandTextElement.innerText = '';
        }
    }
}

        
/**
 * Event Listeners: Connect the HTML buttons to the Calculator class
 * (This part is the same as before, but now calls the new methods)
 */

// Select all buttons and display elements
const numberButtons = document.querySelectorAll('[data-number]');
const operationButtons = document.querySelectorAll('[data-operation]');
const functionButtons = document.querySelectorAll('[data-function]');
const equalsButton = document.querySelector('[data-equals]');
const previousOperandTextElement = document.querySelector('[data-previous-operand]');
const currentOperandTextElement = document.querySelector('[data-current-operand]');

// Create a new calculator instance
const calculator = new Calculator(previousOperandTextElement, currentOperandTextElement);

// Add click event listener for number buttons (0-9, .)
numberButtons.forEach(button => {
    button.addEventListener('click', () => {
        const number = button.innerText || button.dataset.number;
        calculator.appendNumber(number);
    });
});

// Add click event listener for function buttons (AC, +/-, %)
functionButtons.forEach(button => {
    button.addEventListener('click', () => {
        calculator.handleFunction(button.dataset.function);
    });
});

// Add click event listener for operation buttons (+, -, ×, ÷)
operationButtons.forEach(button => {
    button.addEventListener('click', () => {
        calculator.chooseOperation(button.dataset.operation);
    });
});

// Add click event listener for the equals button
equalsButton.addEventListener('click', () => {
    calculator.compute();
});