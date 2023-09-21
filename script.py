import os 

ignore_list = [
    ".gitignore",
    "commiter.bat",
    "README.md",
    "script.py",
    ".vscode",
    ".git"
]

if __name__ == "__main__":
    solved = ""
    for folder in os.listdir():
        if folder not in ignore_list:
            solved += f"* {folder}\n"
    open("SOLVED.md", "w+", encoding="utf-8")\
        .write(str(solved))
