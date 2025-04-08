-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Mar 30, 2025 at 02:42 PM
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
-- Database: `campusmap`
--

-- --------------------------------------------------------

--
-- Table structure for table `classroom`
--

CREATE TABLE `classroom` (
  `classroom_id` int(11) NOT NULL,
  `building_id` int(11) NOT NULL,
  `room_code` varchar(10) NOT NULL,
  `capacity` int(11) NOT NULL,
  `is_available` tinyint(1) DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `classroom`
--

INSERT INTO `classroom` (`classroom_id`, `building_id`, `room_code`, `capacity`, `is_available`) VALUES
(1, 1, 'B1', 30, 1),
(2, 1, 'C1', 30, 1),
(3, 1, 'D1', 30, 1),
(4, 1, 'E1', 30, 1),
(5, 1, 'F1', 30, 1),
(6, 1, 'G1', 30, 1),
(7, 2, 'F3', 20, 1),
(8, 2, 'G3', 20, 1),
(9, 3, 'I2', 40, 1),
(10, 3, 'J2', 40, 1),
(11, 4, 'A3', 35, 1),
(12, 4, 'A4', 35, 1),
(13, 4, 'B3', 35, 1),
(14, 4, 'B4', 35, 1),
(15, 4, 'C3', 35, 1),
(16, 4, 'C4', 35, 1),
(17, 4, 'D3', 35, 1),
(18, 4, 'D4', 35, 1),
(19, 5, 'B6', 50, 1),
(20, 5, 'C6', 50, 1),
(21, 5, 'D6', 50, 1),
(22, 5, 'E6', 50, 1),
(23, 6, 'H7', 60, 1),
(24, 6, 'H8', 60, 1),
(25, 6, 'I7', 60, 1),
(26, 6, 'I8', 60, 1),
(27, 6, 'J7', 60, 1),
(28, 6, 'J8', 60, 1),
(29, 7, 'F10', 25, 1),
(30, 7, 'G10', 25, 1),
(31, 8, 'A10', 45, 1),
(32, 8, 'A9', 45, 1),
(33, 8, 'A8', 45, 1),
(34, 8, 'B10', 45, 1),
(35, 8, 'B9', 45, 1),
(36, 8, 'B8', 45, 1),
(37, 8, 'C10', 45, 1),
(38, 8, 'C9', 45, 1),
(39, 8, 'C8', 45, 1),
(40, 8, 'D10', 45, 1),
(41, 8, 'D9', 45, 1),
(42, 8, 'D8', 45, 1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `classroom`
--
ALTER TABLE `classroom`
  ADD PRIMARY KEY (`classroom_id`),
  ADD KEY `building_id` (`building_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `classroom`
--
ALTER TABLE `classroom`
  MODIFY `classroom_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=58;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `classroom`
--
ALTER TABLE `classroom`
  ADD CONSTRAINT `classroom_ibfk_1` FOREIGN KEY (`building_id`) REFERENCES `building` (`building_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
