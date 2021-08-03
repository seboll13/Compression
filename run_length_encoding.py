import random
import time
import sys

ORIGINAL = sys.argv[1]
COMPRESSED = sys.argv[2]
FILE_SIZE = 333333 # 333'333 is approx 1Mb, 333'333'333 approx 1Gb.

PROB = 1/2

extensions = ('bin', 'txt')


def write_random_bits(original, n):
    """Write bits in original file"""
    o = open(original, 'w')
    for _ in range(n):
        r = random.uniform(0, 1)
        # create groups of zeroes and ones
        for _ in range(random.randint(1,5)):
            o.write('0') if r < PROB else o.write('1')
    o.close()


def rle_compression(original, compressed):
    """Run-length encoding algorithm"""
    c = open(compressed, 'w')
    with open(original) as f:
        curr_bit = f.read(1)
        counter = 1
        while True:
            next_bit = f.read(1)
            if not next_bit:
                c.write(f"{bin(counter)[2:]}{curr_bit}")
                break
            else:
                if next_bit == curr_bit:
                    counter += 1
                else:
                    c.write(f"{bin(counter)[2:]}{curr_bit}")
                    counter = 1
                curr_bit = next_bit
    f.close()
    c.close()


def print_stats(original, compressed):
    """Print file sizes and comparison statistics"""
    o = open(original, 'r')
    c = open(compressed, 'r')
    orig_size, comp_size = len(o.read()), len(c.read())
    print(f"Size of original file   : {orig_size} bits")
    print(f"Size of compressed file : {comp_size} bits")
    print(f"Size comparison factor  : {(comp_size / orig_size):.3f}")


def main():
    # Error handling
    if len(sys.argv) != 3:
        print('error in arguments')
        sys.exit(1)
    
    assert ORIGINAL.endswith(extensions), 'initial filename is not valid'
    assert COMPRESSED.endswith(extensions), 'initial filename is not valid'

    # Main program
    write_random_bits(ORIGINAL, FILE_SIZE)
    start = time.time()
    rle_compression(ORIGINAL, COMPRESSED)
    print_stats(ORIGINAL, COMPRESSED)
    end = time.time()

    # Time results
    print(f'Total execution time    : {(end - start):.3f} seconds')


if __name__ == '__main__':
    main()