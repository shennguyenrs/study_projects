import os

def file_path(file_name):
    """
    Change directory to open file in 'resources', from the current 'lib' folder

    Parameters:
    -----------
        dir_name : str
            Name of the directory contain the file
        file_name : str
            Name of the file

    Returns:
    --------
        path : str
            Path to the file

    Raises:
    -------

    """

    # Module name due to run python3 -m
    os.chdir(os.path.dirname(__file__))
    os.chdir("..")
    to_parent_dir = os.getcwd()
    dir_name = "resources"

    path = os.path.join(to_parent_dir, dir_name, file_name)

    return path
