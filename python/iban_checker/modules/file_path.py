import os

def file_path(dir_name, file_name):
    """
    Change directory to open file in 'resources', from the current 'modules' folder

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

    to_parent_dir = os.chdir(os.path.dirname(os.getcwd()))
    path = os.path.join(to_parent_dir, dir_name, file_name)

    return path
