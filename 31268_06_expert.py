QUESTIONS_ROOM_SERVICE = [
    'Did you order room service recently?',
    'Were the items in your room service order delivered on time?',
    'Did you receive the correct items in your room service order?',
    'Were the food and beverages in your room service order satisfactory?',
    'Was cleanliness maintained during the room service and food delivery?',
    'Was the delivered food healthy and nutritious?',
    'Did the room service incharge provide the necessary services?'
    'Was he/she polite and cooperative?'
]

def roomServiceComplaintSystem(questions):
    no_count = 0
    for question in questions:
        print(question + " (Y/N) ")
        ans = input("> ").lower()
        if ans == 'n':
            no_count += 1

    print("\n\n")
   

    if no_count >= 5:
        print("Based on your answers, your room service complaint is HIGH.")
        print("Please contact the hotel management immediately for resolution.")

    elif no_count >= 3:
        print("Based on your answers, your room service complaint is MEDIUM.")
        print("We recommend notifying the hotel staff about your concerns for appropriate action.")

    elif no_count >= 1:
        print("Based on your answers, your room service complaint is LOW.")
        print("You may want to share your feedback with the hotel staff for improvement.")

    else:
        print("No significant room service complaints reported. If you have additional concerns, please inform the hotel staff.")

    a = input('Do you have any specific complaints / feedback? (Y/N)').lower()
    if a == 'y':
        feedback = input('Please type your feedback in short: ')

    print("\n\nThank you for sharing your feedback. The hotel staff will address your concerns promptly.")
    print("\nFor any further assistance or urgent matters, please contact the hotel front desk. 0999669955")

if __name__ == '__main__':
    print("\n\n\t\tWelcome To The HOTEL ROOM SERVICE COMPLAINT SYSTEM\n")
    print("\tNote: Please answer the following questions regarding your room service experience.\n\n")
    roomServiceComplaintSystem(QUESTIONS_ROOM_SERVICE)
