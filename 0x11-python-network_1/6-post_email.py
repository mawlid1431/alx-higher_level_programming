import requests
import sys

if __name__ == "__main__":
    # Check if the correct number of command-line arguments is provided
    if len(sys.argv) != 3:
        print("Usage: ./6-post_email.py <URL> <email>")
        sys.exit(1)

    # Extract the URL and email from command-line arguments
    url = sys.argv[1]
    email = sys.argv[2]

    # Create a dictionary with the email parameter
    data = {"email": email}

    # Send a POST request with the email parameter to the specified URL
    response = requests.post(url, data=data)

    # Print the email and the response body
    print(f"Your email is: {email}")
    print(response.text)

