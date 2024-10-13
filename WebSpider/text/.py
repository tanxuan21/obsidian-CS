# import requests
# res = requests.get('https://hipala.github.io/js-example/')
# print(res.text)

from selenium import webdriver
from selenium.webdriver.common.by import By
import os
driver = webdriver.Chrome()
driver.get('https://www.meta.com/en-gb/experiences/i-am-cat/6061406827268889/#reviews')
# .xeuugli, .x2lwn1j, .x78zum5, .xdt5ytf, .xozqiw3, .xgpatz3
reviews = driver.find_element(By.ID, "reviews")

for key, value in reviews.__dict__.items():
    print(f"{key}: {value}")
print(reviews.get_attribute("outerHTML"))
# f = open("data.html","w")
# f.write(reviews)
# f.close()
# driver.quit()