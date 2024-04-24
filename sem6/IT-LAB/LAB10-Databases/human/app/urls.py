from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('update/<int:human_id>/', views.update_human, name='update_human'),
    path('delete/<int:human_id>/', views.delete_human, name='delete_human'),
]
