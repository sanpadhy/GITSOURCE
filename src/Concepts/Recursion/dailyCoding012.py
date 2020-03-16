def get_step_combos(num_steps, step_sizes):
    combos = list()
    
    if num_steps < min(step_sizes):
        return combos
    
    for step_size in step_sizes:
        if num_steps == step_size:
            combos.append([step_size])
        elif num_steps > step_size:
            child_combos = get_step_combos(num_steps - step_size, step_sizes)
            for child_combo in child_combos:
                combos.append([step_size] + child_combo)
    return combos


# another way is to build a binary tree. in which left node would be 1 steps and right 
# node will be two steps. Build the tree with multiple options. 
# Print all paths from root. But limited to only two steps {1, 2}. 

