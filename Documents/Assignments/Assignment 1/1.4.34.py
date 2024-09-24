function find_secret_number(N):
    lower_bound = 1
    upper_bound = N
    guess = N // 2
    previous_guess = None

    while true:
        if guess == secret_number:
            return guess  # Correct guess

        # Ask if hotter or colder compared to previous guess
        if previous_guess is not None:
            if is_hotter(previous_guess, guess):
                # Narrow the search to the closer half
                if guess > previous_guess:
                    upper_bound = guess
                else:
                    lower_bound = guess
            else:
                # Narrow the search to the farther half
                if guess > previous_guess:
                    lower_bound = guess
                else:
                    upper_bound = guess
        
        # Update the guess by binary search
        previous_guess = guess
        guess = (lower_bound + upper_bound) // 2
