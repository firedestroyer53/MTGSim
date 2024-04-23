import requests
import os
import re
from PIL import Image

def download_card_image(card_name, save_path):
    # Encode the card name to be URL-safe
    encoded_card_name = card_name.replace(' ', '+')

    # Construct the URL for the Scryfall API endpoint
    url = f'https://api.scryfall.com/cards/named?fuzzy={encoded_card_name}'

    try:
        # Make the GET request to the API
        print(f"Downloading '{card_name}'...")
        response = requests.get(url)
        response.raise_for_status()  # Check for any errors in the response

        # Parse the JSON response
        data = response.json()

        # Check if 'image_uris' key exists in the response
        if 'image_uris' in data:
            # Get the URL of the card image
            image_url = data['image_uris']['png']

            # Download the image
            image_response = requests.get(image_url)

            # Save the image to the specified path
            with open(save_path, 'wb') as image_file:
                image_file.write(image_response.content)

            print(f"Successfully downloaded '{card_name}' image to '{save_path}'")
        else:
            print(f"Error: Image URL not found for '{card_name}'")
    except requests.exceptions.RequestException as e:
        print(f"Error downloading '{card_name}' image: {e}")

def convert_to_bmp(input_path, output_path):
    try:
        # Open the PNG image using Pillow
        with Image.open(input_path) as img:
            # Convert and save the image as BMP format
            img.save(output_path)
            print(f"Successfully converted '{input_path}' to BMP format at '{output_path}'")
    except Exception as e:
        print(f"Error converting '{input_path}' to BMP format: {e}")

# Read the card names from decklist.txt
decklist_file = 'decklist.txt'
save_folder = 'downloaded_images'
bmp_folder = 'bmp_images'

if not os.path.exists(save_folder):
    os.makedirs(save_folder)

if not os.path.exists(bmp_folder):
    os.makedirs(bmp_folder)

with open(decklist_file, 'r') as f:
    card_names = [re.sub(r'\d+', '', line.strip()) for line in f.readlines()]

# Download images for each card
for card_name in card_names:
    save_path = os.path.join(save_folder, f"{card_name.replace(' ', '')}.png")
    download_card_image(card_name[1:], save_path)
    bmp_save_path = os.path.join(bmp_folder, f"{card_name.replace(' ', '')}.bmp")
    convert_to_bmp(save_path, bmp_save_path)
    print()  # Add an empty line for readability in the console
