import os
import shutil


def create_range_directory(base_path, start, end):
    """Creates the range directory and its subdirectories."""
    range_dir = f"{start}_{end}"
    range_path = os.path.join(base_path, range_dir)
    os.makedirs(range_path, exist_ok=True)

    mid_point = (start + end) // 2
    subrange1_dir = f"{start}_{mid_point}"
    subrange1_path = os.path.join(range_path, subrange1_dir)
    os.makedirs(subrange1_path, exist_ok=True)

    subrange2_dir = f"{mid_point + 1}_{end}"
    subrange2_path = os.path.join(range_path, subrange2_dir)
    os.makedirs(subrange2_path, exist_ok=True)

    return subrange1_path, subrange2_path


def move_directories(base_path):
    """Moves the directories into the newly created structure."""
    dirs = sorted(
        [
            d
            for d in os.listdir(base_path)
            if os.path.isdir(os.path.join(base_path, d)) and d.isdigit()
        ],
        key=int,
    )

    for dir_name in dirs:
        dir_num = int(dir_name)
        range_start = (dir_num - 1) // 100 * 100 + 1
        range_end = range_start + 99

        subrange1_path, subrange2_path = create_range_directory(
            base_path, range_start, range_end
        )

        if range_start <= dir_num <= (range_start + range_end) // 2:
            shutil.move(os.path.join(base_path, dir_name), subrange1_path)
        else:
            shutil.move(os.path.join(base_path, dir_name), subrange2_path)


def main():
    base_path = os.getcwd()
    move_directories(base_path)


if __name__ == "__main__":
    main()
