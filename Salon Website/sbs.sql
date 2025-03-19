-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Mar 14, 2025 at 12:44 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `sbs`
--

-- --------------------------------------------------------

--
-- Table structure for table `appointments`
--

CREATE TABLE `appointments` (
  `FulName` varchar(45) NOT NULL,
  `PhoneNumber` varchar(45) NOT NULL,
  `Email` varchar(56) NOT NULL,
  `DateTime` varchar(345) NOT NULL,
  `Sevice` varchar(790) NOT NULL,
  `ToeEnhancements` varchar(34) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `appointments`
--

INSERT INTO `appointments` (`FulName`, `PhoneNumber`, `Email`, `DateTime`, `Sevice`, `ToeEnhancements`) VALUES
('Kyle Cox', '123-2345', 'Kyle.cox@mybcc.edu.bb', '2022-06-22T15:07', 'Hard Gell Fullsets - short', 'on'),
('Shanice Smith', '234-3475', '	 Shanice.Smith@mybcc.edu.bb', '2022-06-02T12:10', 'Hard Gell Fullsets - short', 'on'),
('Aaron Waterman', '2345678', 'lilian246@gmail.com', '2022-06-03T12:36', 'Hard Gell Fullsets - medium', 'on');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `usersId` int(11) NOT NULL,
  `usersName` varchar(128) NOT NULL,
  `usersEmail` varchar(128) NOT NULL,
  `usersUid` varchar(128) NOT NULL,
  `usersPwd` varchar(128) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`usersId`, `usersName`, `usersEmail`, `usersUid`, `usersPwd`) VALUES
(1, 'Kyle Cox', 'Kyle.cox@mybcc.edu.bb', 'kyle5775', '$2y$10$lpCU5KKr2w6Idv34XA357.EGGeFwMxUxOq7moPyXdRLz57byB.m4e'),
(2, 'Shanice Smith', 'Shanice.Smith@mybcc.edu.bb', 'ShanShan234', '$2y$10$36rsCbcut57ESRtdGb9FQevLCmcrFXFQxGQmwwr3ZzgrlzjTisWou'),
(3, 'Aaron Alleyne-Waterman', 'Aaron.Alleyne-Waterman@mybcc.edu.bb', 'Aaron246', '$2y$10$4ezLgh0mQlc69YT1PgNby.LACqxVSeanf9sZJXZBlgPHbdQPbTaMm'),
(4, 'Lilly Smith', 'lilian246@gmail.com', 'lilly246', '$2y$10$xZWVhm6vln8ynINSuL/O6OWP0HdyyeKCOxhampWbz6WDssLN/AKhO'),
(5, 'Abigail Murray', 'kyleacox11@gmail.com', 'lkkijjy', '$2y$10$m6MpEV.8liitLbMPiaSl4ejqAMBWvSe.p6nFE5.XUcuu2n3h1yjIe'),
(6, 'Abigail Murr', 'kyleacox@gmail.com', 'kulu89898', '$2y$10$3HJP.Frzc2oRaBv4vHAhLekVp/qCxb7pcqtAz351vKFf7UpmL.14a'),
(7, 'Abigail Murray', 'kyleaco@gmail.com', 'gmail', '$2y$10$l5mYykQaBs1W/FS7ZwNl5.AwV1/4qw0iXvmtqrdP9IByjXJUEmj2m');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`usersId`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `usersId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
