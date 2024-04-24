from django.urls import path, include
from . import views

urlpatterns = [
    path('achieve/', views.achieve, name="achieve"),
    path('achieve/createblog/', views.createblog, name="createblog")
]
