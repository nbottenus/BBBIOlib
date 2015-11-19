from distutils.core import setup
from Cython.Build import cythonize

setup(
    name="ADC"
    ext_modules = cythonize("ADC.pyx")
)
