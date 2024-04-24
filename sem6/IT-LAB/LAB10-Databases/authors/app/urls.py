# urls.py

from django.urls import path
from . import views

urlpatterns = [
    path('add/author/', views.add_author, name='add_author'),
    path('add/publisher/', views.add_publisher, name='add_publisher'),
    path('add/book/', views.add_book, name='add_book'),
    path('list/authors/', views.author_list, name='author_list'),
    path('list/publishers/', views.publisher_list, name='publisher_list'),
    path('list/books/', views.book_list, name='book_list'),
]
