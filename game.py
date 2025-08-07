import random

class Item:
    def __init__(self, name, price):
        self.name = name
        self.price = price

def get_items():
    return [
        Item("Toaster", 19.99),
        Item("Blender", 49.99),
        Item("Microwave Oven", 89.99),
        Item("Vacuum Cleaner", 129.99),
        Item("Coffee Maker", 39.99),
        Item("Smartphone", 699.99),
        Item("Laptop", 999.99),
        Item("Headphones", 199.99),
        Item("Smart Watch", 249.99),
        Item("Tablet", 329.99)
    ]

def contestants_bids(num_contestants, min_bid, max_bid):
    bids = []
    for i in range(num_contestants):
        while True:
            try:
                bid = float(input(f"Contestant {i+1}, enter your bid between ${min_bid:.2f} and ${max_bid:.2f}: $"))
                if min_bid <= bid <= max_bid:
                    bids.append(bid)
                    break
                print("Bid out of range.")
            except ValueError:
                print("Invalid input. Enter a number.")
    return bids

def main():
    print("Welcome to The Price is Right!\n")
    items = get_items()
    selected_item = random.choice(items)
    print(f"Today's item: {selected_item.name}\n")

    num_contestants = 4
    min_bid = 1.00
    max_bid = selected_item.price * 2

    print(f"Actual retail price is hidden. Four contestants will bid as close as possible without going over!\n")
    bids = contestants_bids(num_contestants, min_bid, max_bid)

    print("\nBids:")
    for i, bid in enumerate(bids):
        print(f"Contestant {i+1}: ${bid:.2f}")

    # Find the highest bid not over the price
    winning_index = -1
    winning_bid = -1
    for i, bid in enumerate(bids):
        if bid <= selected_item.price and bid > winning_bid:
            winning_bid = bid
            winning_index = i

    print(f"\nActual retail price: ${selected_item.price:.2f}")
    if winning_index == -1:
        print("All contestants overbid! No winner this round.")
    else:
        print(f"Contestant {winning_index+1} wins with a bid of ${winning_bid:.2f}!")

if __name__ == "__main__":
    main()
