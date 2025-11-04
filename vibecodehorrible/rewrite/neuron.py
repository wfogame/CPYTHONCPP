import numpy as np

input_value = 0.5
target_output = 1.0

weight = np.random.randn()
bias = np.random.randn()
learning_rate = 0.1

for step in range(1000):
    # Calculate output
    output = weight * input_value + bias
    
    # How wrong are we?
    loss = (output - target_output) ** 2
    
    # Figure out how to adjust weight and bias
    change_in_loss_per_change_in_output = 2 * (output - target_output)
    change_in_output_per_change_in_weight = input_value
    change_in_output_per_change_in_bias = 1
    
    # Update
    weight -= learning_rate * change_in_loss_per_change_in_output * change_in_output_per_change_in_weight
    bias -= learning_rate * change_in_loss_per_change_in_output * change_in_output_per_change_in_bias
    
    if step % 100 == 0:
        print(f"Step {step}: loss={loss:.4f}, output={output:.4f}")
