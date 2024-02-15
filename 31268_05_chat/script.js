document.addEventListener('DOMContentLoaded', function() {
    const sendButton = document.getElementById('send-button');
    sendButton.addEventListener('click', function() {
        sendMessage();
    });
});
function sendMessage() {
    var userInput = document.getElementById('user-input').value;
    if (userInput.trim() !== '') {
        appendMessage('user', userInput);
        var botResponse = getBotResponse(userInput);
        setTimeout(function () {
            appendMessage('bot', botResponse);
        }, 500);
        document.getElementById('user-input').value = '';
    }
}
function getBotResponse(userInput) {
    var lowerCaseInput = userInput.toLowerCase();
    if (lowerCaseInput.includes('hello') || lowerCaseInput.includes('hi')) {
        return 'Hello! Welcome to Sports Equipment Store. How can I assist you today?';
    } else if (lowerCaseInput.includes('how are you')) {
        return 'I am just a chatbot programmed to assist you with sports equipment inquiries!';
    } else if (lowerCaseInput.includes('your name')) {
        return 'I am the SportsBot.';
    } else if (lowerCaseInput.includes('time')) {
        var currentTime = new Date().toLocaleTimeString();
        return 'The current time is ' + currentTime + '.';
    } else if (lowerCaseInput.includes('website')) {
        return 'Our website offers a wide range of sports equipment for all your needs.';
    } else if (lowerCaseInput.includes('services')) {
        return 'Our services include providing high-quality sports equipment, fast shipping, and excellent customer support.';
    } else if (lowerCaseInput.includes('contact')) {
        return 'You can contact us by Phone: +1-800-SPORTS-1 or Email: support@sportsequipment.com.';
    } else if (lowerCaseInput.includes('help')) {
        return 'If you need assistance, you can visit our <a href="https://www.sportsequipment.com/help" target="_blank">Help Center</a> or ask me specific questions.';
    } else if (lowerCaseInput.includes('bye')) {
        return 'Goodbye! If you have more questions, feel free to ask.';
    } else {
        return 'I\'m sorry, I didn\'t understand that. Can you please ask another question related to sports equipment?';
    }
}
function appendMessage(sender, message) {
    var chatMessages = document.getElementById('chat-messages');
    var messageDiv = document.createElement('div');
    messageDiv.className = sender === 'user' ? 'user-message' : 'bot-message';
    messageDiv.innerHTML = message;
    chatMessages.appendChild(messageDiv);
    chatMessages.scrollTop = chatMessages.scrollHeight;
}
